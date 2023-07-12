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
 ./toBin <input> <output>
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
./kplexlist <dataset> <k> <lb>
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

**Run The Example**
```bash
./kplexlist ../dataset/jazz.bin 4 12
```
#### Result
Partial results are shown in the following table
| Dataset | $n$ | $m$ | $k$ | $q$ | #𝑘-plexes | time/sec |
|-------------|:-----:|:------:|:-:|:--:|:--------:|:-----:|
| jazz | 198| 2742 | 4 | 12 | 2745953 | 2.87 |
| wiki-vote | 7116| 100763 | 3 | 20 | 156727 | 4.15 |
| soc-epinions| 75879 | 405740 | 4 | 30 | 13172906 | 93.47 |
| email-euall| 265009 | 364481 | 3 | 12 | 32639016 | 56.22 |
### Parallel Algorithm
#### Compile The Code
```shell
cd Plex_par
make
```
#### Usage Instruction
```bash
./kplexlist <dataset> <k> <lb> <thread-number>
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

thread-number is the number of threads used

**Run The Example**
```bash
./kplexlist ../dataset/jazz.bin 4 12 16
```
#### Result
We tested our parallel algorithm on large graphs and demonstrated the speedup achieved when setting the timeout threshold $\tau=0.1 \mathrm{ms}$. Here are some partial results.
| Dataset | $n$ | $m$ | $k$ | $q$ | #𝑘-plexes | time/sec |
|-------------|:------:|:---------:|:-:|:--:|:--------:|:------:|
| enwiki-2021 | 6253897| 136494843 | 3 | 50 | 40997 | 1008.26 |
| it-2004| 41290648 | 1027474947 | 2 | 1000 | 66067542 | 934.80 |

