module lfsr(
    input   logic       clk,
    input   logic       rst,
    input   logic       en,
    output  logic [3:0] data_out
);

logic [3:0] sreg;

always_ff @ (posedge clk, posedge rst)
    if(rst) // cpp file runs reset immediately to set initial value
        // why initalise as 15?
        sreg <= 4'b1; // sets initial value
    else 
        sreg <= {sreg[2:0], sreg[3] ^ sreg[2]};

assign data_out = sreg;
endmodule
