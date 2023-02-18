#include <stdio.h>

void compute(int numCandidates, int numProgress, int response[]) {
    int VPC[numCandidates];
    // votesPerCandidate = VPC;
    for (int i = 0; i < numCandidates; i++) {
        VPC[i] = 0;
    }
    for (int i = 0; i < numCandidates; i++) {
        VPC[response[i] - 1]++;
    }
    int IVPC[numCandidates];
    // indexOfVotesPerCandidate = IVPC
    for (int i = 0; i < numCandidates; i++) {
        IVPC[i] = i + 1;
    }
    // sort VPC
    for (int i = 0; i < numCandidates - 1; i++) {
        for (int j = 0; j < numCandidates; j++) {
            if (VPC[(j)] > VPC[(j + 1)]) {
                // swap VPC
                int temp = VPC[(j + 1)];
                VPC[(j + 1)] = VPC[j];
                VPC[j] = temp;
                // swap IVPC
                temp = IVPC[(j + 1)];
                IVPC[(j + 1)] = IVPC[j];
                IVPC[j] = temp;
            }
        }
    }
    // print
    for (int i = numCandidates - 1; i > numCandidates - 1 - numProgress; i--) {
        printf("%d ", IVPC[i]);
    }
}
int main() {
    int numCandidates, numProgress;
    scanf("%d %d", &numCandidates, &numProgress);
    int response[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        scanf("%d", &response[i]);
    }
    compute(numCandidates, numProgress, response);
    return 0;
}
