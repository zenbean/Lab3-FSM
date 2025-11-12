#include "Vf1_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vf1_fsm* Vf1 = new Vf1_fsm;

    if (vbdOpen()!=1) return(-1);
    vbdHeader("Lab 3: F1 countdown");
    vbdSetMode(1);

    // initialise values
    Vf1->clk = 1;
    Vf1->rst = 1;
    Vf1->en = 0;

    for(i=0; i<2000; i++){
        Vf1->rst=(i<2);
        Vf1->en = vbdFlag();
        for (clk = 0; clk < 2; clk++) {
            Vf1->clk = !Vf1->clk;
            Vf1->eval();
        }
        vbdBar(Vf1->data_out & 0xFF);
        vbdCycle(i + 1);

        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
            exit(0); // ... exit if finish OR 'q' pressed
    }
    vbdClose();
    delete Vf1;
    exit(0);
}