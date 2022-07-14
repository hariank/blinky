#include <memory>
#include <verilated.h>
#include "Vled_blink.h"
#include "testbench.h"

using namespace std;

int main(int argc, char** argv, char** env) {
    // Prevent unused variable warnings
    if (false && argc && argv && env) {}

    const unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    // Set debug level, 0 is off, 9 is highest presently used
    contextp->debug(0);
    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);

    auto tb = make_unique<TestBench<Vled_blink>>();

    tb->openTrace("logs/trace.vcd");

    /* 2**20 = 1048576 ticks till counter changes */
    for(int i = 0; i < 5 * 1048576 + 100; i++)
    {
        tb->tick();
    }

    tb->closeTrace();

    return 0;
}
