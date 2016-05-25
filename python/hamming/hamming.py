def distance(strand_1, strand_2):
    return sum([n1 != n2 for (n1, n2) in zip(strand_1, strand_2)])
