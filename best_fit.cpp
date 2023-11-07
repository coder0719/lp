#include <iostream>
using namespace std;

int main() {
    int frag[25], b[25], f[25], bf[25], ff[25];
    int nb, nf;

    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "Enter the size of the blocks:\n";
    for (int i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
        bf[i] = 0; 
    }

    cout << "Enter the size of the files:\n";
    for (int i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
        ff[i] = 0; 
    }

    for (int i = 1; i <= nf; i++) {
        int bestFitBlock = -1;
        int smallestBlockSize = 25;

        for (int j = 1; j <= nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i] && b[j] < smallestBlockSize) {
                bestFitBlock = j;
                smallestBlockSize = b[j];
            }
        }

        if (bestFitBlock != -1) {
            ff[i] = bestFitBlock;
            bf[bestFitBlock] = 1; // Mark the block as allocated
            frag[i] = b[bestFitBlock] - f[i];
        }
    }

    cout << "\nFile No\tFile Size\tBlock No\tBlock Size\tFragment" << endl;
    for (int i = 1; i <= nf; i++) {
        if (ff[i] != 0) {
            cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
        }
    }

    return 0;
}
