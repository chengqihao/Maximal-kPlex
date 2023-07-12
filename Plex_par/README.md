# Branch and Bound Algorithm
# Compile the code:
```shell
make
```

# Usage
  ./kplexlist \<file\> \<k\> \<lb\> [thread]

k is the maximum number of non-neighbors of a k-plex

lb is the lower bound of k-plex.

thread is the number of threads used

e.g.

```bash
./kplexlist ../dataset/jazz.bin 4 12 16
```

# Format

The input graph should be a binary format.
One can convert an edge list format graph file (SNAP format) into this binary format by a converter `toBin` .

usage:

  ./toBin \<input\> \<output\>

e.g.

```bash
./toBin ../dataset/jazz.txt ../datatset/jazz.bin
```

