def to_rna(dna_strand):
    dna_to_rna_transcription = {'A': 'U', 'C': 'G', 'G': 'C', 'T': 'A'}
    return ''.join([dna_to_rna_transcription[n] for n in dna_strand])