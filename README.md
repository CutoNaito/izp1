# Keyfilter
A program for address keyfiltering.

### Installation:
#### Linux:
```
git clone https://github.com/CutoNaito/izp1.git
cd izp1
make
```

#### Windows:
1. switch to linux
2. do the above

### Usage:
Fill /bin/address.txt with as many adresses as you want (one per line). For example:
```
Praha
Brno
Bratislava
```

Run the program with letters you want to filter as an argument and address.txt as the input file.
`bin/keyfilter <ARGUMENT> <bin/address.txt`

For example:
```
bin/keyfilter Br <bin/address.txt
```
The output should look like this:
```
Enable: AN

(A in BrAtislava, N in BrNo)
```
