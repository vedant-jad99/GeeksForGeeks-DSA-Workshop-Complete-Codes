def recurring_char(string):
    checked = set()
    for i in string:
        if i in checked:
            return i
        checked.add(i)
    return None

if __name__ == "__main__":
    string = input()
    print(recurring_char(string))
