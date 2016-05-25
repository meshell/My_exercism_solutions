def distance(strand_1, strand_2):
    hamming_distance = 0
    for (n1, n2) in zip(strand_1, strand_2):
        hamming_distance += 0 if n1 == n2 else 1
    return hamming_distance
