# Efficient Enumeration of Large Maximal $k$-Plexes
Source codes and appendix of paper “Efficient Enumeration of Large Maximal $k$-Plexes”.

## Algorithm
The sequential algorithm is in the file "Sequential".

The parallel version is in the file "Parallel".

## Datasets
We provide some small datasets in the file "datasets". 

The `.txt` files are the original datasets, while files with the suffix `.bin` are preprocessed files we use. 

We only use binary format for the input graph which can be converted by `toBin` from [ListPlex](https://github.com/joey001/ListPlex).

`toBin` is also included in “Sequential” and "Parallel" .
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
cd Sequential
make
```
#### Usage Instruction
```bash
./PlexEnum [-d <dataset>] [-k <k>] [-lb <lb>]
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

**Run The Example**
```bash
./PlexEnum -d ../dataset/jazz.bin -k 4 -lb 12
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
cd Parallel
make
```
#### Usage Instruction
```bash
./PlexEnum [-d <dataset>] [-k <k>] [-lb <lb>] [-tau <timeout threshold>(default 0.1)] [-t <thread number>]
```
k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

tau is the user-defined task timeout threshold

t is the number of threads used

**Run The Example**
```bash
./PlexEnum -d ../dataset/jazz.bin -k 4 -lb 12 -tau 0.1 -t 16
```
#### Result
We tested our parallel algorithm on large graphs and demonstrated the speedup achieved when setting the timeout threshold $\tau=0.1 \mathrm{ms}$. Here are some partial results.
| Dataset | $n$ | $m$ | $k$ | $q$ | #𝑘-plexes | time/sec |
|-------------|:------:|:---------:|:-:|:--:|:--------:|:------:|
| enwiki-2021 | 6253897| 136494843 | 3 | 50 | 40997 | 1008.26 |
| it-2004| 41290648 | 1027474947 | 2 | 1000 | 66067542 | 934.80 |

