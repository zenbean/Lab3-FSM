module light #(
    parameter   N_WIDTH = 16,
                DATA_WIDTH = 8
)(
    input   logic   [N_WIDTH-1:0]       N,
    input   logic                       en,
    input   logic                       rst,
    input   logic                       clk,
    output  logic   [DATA_WIDTH-1:0]    data_out,
    output  logic                       tick          
);

clktick myTick (
    .clk    (clk),
    .rst    (rst), 
    .N      (N),
    .en     (en),
    .tick   (tick)
);

f1_fsm myF1 (
    .clk        (clk),
    .rst        (rst),
    .en         (tick),
    .data_out   (data_out)
);

endmodule
