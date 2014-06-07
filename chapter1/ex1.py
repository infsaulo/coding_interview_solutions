import sys

def main():
    alreadyHasChar = [False for i in xrange(128)]
    string = sys.stdin.readline()

    for ch in string:
        if alreadyHasChar[ord(ch)]:
            return False
        alreadyHasChar[ord(ch)] = True

    return True

if __name__ == "__main__":
    print main()
