def to_rna(dna_strand):
    dna_to_rna_transcription = dict([('A', 'U'), ('C', 'G'), ('G', 'C'), ('T', 'A')])
    rna_strand = ''
    for nucleotide in dna_strand:
        rna_strand += dna_to_rna_transcription[nucleotide]
    return rna_strand
