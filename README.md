# kPlexList
The code of paper “Efficient Enumeration of Large Maximal k-Plexes”

## Algorithm
The sequential algorithm is in the file "Plex_seq".

The parallel version is in the file "Plex_par".

## Datasets
We provide some small datasets in the file "datasets". 

The `.txt` files are the original datasets, while files with the suffix `.bin` are preprocessed files we use. 

We only use binary format for the input graph which can be converted by `toBin` from [ListPlex](https://github.com/joey001/ListPlex). 
```bash
 ./toBin \<input\> \<output\>
```
**Example**
```bash
 ./toBin ./dataset/jazz.txt ./dataset/jazz.bin
```
All the datasets can be found on SNAP and LAW
## Experiment
### Tested Environment
* RedHatEnterpriseServer 7.9
* C++ 14
* g++ - 7.2.0
### Sequential Algorithm
#### Compile The Code
```shell
cd Plex_seq
make
```
#### Usage Instruction
```bash
./kplexlist \<dataset\> \<k\> \<lb\>
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

**Run The Example**
```bash
./kplexlist ../dataset/jazz.bin 4 12
```
#### Result
### Parallel Algorithm
#### Compile The Code
```shell
cd Plex_par
make
```
#### Usage Instruction
```bash
./kplexlist \<dataset\> \<k\> \<lb\> \<thread-number\>
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

thread-number is the number of threads used

**Run The Example**
```bash
./kplexlist ../dataset/jazz.bin 4 12 16
```
#### Result

