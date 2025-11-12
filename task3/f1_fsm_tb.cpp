#include "Vf1_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    Vf1_fsm* f1_fsm = new Vf1_fsm;
    if (vbdOpen()!=1) return(-1);
    vbdHeader("Lab 3: F1 countdown");

    f1_fsm->clk = 1;
    f1_fsm->rst = 1;

    const int CLOCK_COUNT = 1000000;
    for (i = 0; i < CLOCK_COUNT; i++) {
        f1_fsm->rst = (i < 2);
        f1_fsm->N = vbdValue();
        for (clk = 0; clk < 2; clk++) {
            f1_fsm->clk = !f1_fsm->clk;
            f1_fsm->eval();
        }
        
        vbdBar(f1_fsm->data_out & 0xFF);
        vbdCycle(i + 1);

        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            exit(0);
        }
    }

    vbdClose();
    exit(0);
}
