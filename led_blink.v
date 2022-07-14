//
`default_nettype none
//
module led_blink (i_clock, 
  o_led);
  input wire i_clock;
  output wire o_led;

  reg [27:0] counter;

  always @(posedge i_clock) begin
    counter <= counter + 1;
  end

  // which bit we use determines blink frequency 
  assign o_led = counter[19]; 

  initial begin
    $display("[%0t] Model running...\n", $time);
  end

endmodule
