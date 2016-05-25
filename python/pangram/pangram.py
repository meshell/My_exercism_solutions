import string

def is_pangram(sentence):
    for c in string.ascii_lowercase:
        if sentence.lower().find(c) == -1:
            return False
    return True