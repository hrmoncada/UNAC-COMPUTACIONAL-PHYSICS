#include <stdio.h>
#include <stdlib.h>

/**
 * Estimation of Pi via Monte Carlo simulation.
 *
 * Serial version.
 */

// Declare functions defined further below
static long do_monte_carlo(long num_trials);
static double next_random();

int main(int argc, char *argv[]) {
    long num_trials; // Number of Monte Carlo trials to perform
    long success_count; // Number of MC successes recorded
    double pi_estimate; // Final Pi estimate

    // Read requested number of trials from command line arguments
    if (argc != 2) {
        fputs("Required argument: <number of trials>\n", stderr);
        return EXIT_FAILURE;
    }
    num_trials = atol(argv[1]);
    if (num_trials <= 0) {
        fputs("Number of trials must be a positive long integer\n", stderr);
        return EXIT_FAILURE;
    }

    // Run specified number of Monte Carlo trials
    success_count = do_monte_carlo(num_trials);

    // Compute our resulting estimate for pi
    pi_estimate = 4.0 * success_count / num_trials;

    // Output final result
    printf("pi=~%0.8f num_trials=%ld success_count=%ld\n",
            pi_estimate, num_trials, success_count);

    // Exit happily
    return EXIT_SUCCESS;
}

/**
 * We define a wee helper macro to square a number. This is used
 * in do_monte_carlo() below to make things a bit easier to read.
 */
#define SQUARE(x) ((x)*(x))

/**
 * Runs the Monte Carlo simulation for the given number
 * of trials, returning the number of successful samples.
 */
long do_monte_carlo(long num_trials) {
    long i, success_count;
    double x, y;

    success_count = 0;
    for (i = num_trials; i > 0; --i) {
        x = next_random();
        y = next_random();
        if (SQUARE(x-0.5) + SQUARE(y-0.5) < SQUARE(0.5)) {
            ++success_count;
        }
    }
    return success_count;
}

/**
 * Returns a pseudo-random number in the range [0,1).
 *
 * NOTE: You would probably want to use a better random
 * number generator than this!
 */
double next_random() {
    return (double) rand() / RAND_MAX;
}
