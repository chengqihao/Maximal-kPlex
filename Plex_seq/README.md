# Branch and Bound Algorithm
# Compile the code:
```shell
make
```

# Usage
  ./kplexlist \<file\> \<k\> \<lb\>

k is the maximum number of non-neighbors of a k-plex
lb is the lower bound of k-plex.

e.g.

```bash
./kplexlist ../dataset/jazz.bin 4 12
```

# Format
We use binary format for the input graph which can be converted by `toBin`. 

usage:

  ./toBin \<input\> \<output\>

e.g.

```bash
./toBin ../dataset/jazz.txt ../datatset/jazz.bin
```

