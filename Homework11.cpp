def main():
    while True:
        print("\n=== MENU ===")
        print("1. Delete character by index")
        print("2. Delete all occurrences of a character")
        print("3. Insert character at index")
        print("4. Replace '.' with '!'")
        print("5. Count character occurrences")
        print("6. Count letters, digits, and others")
        print("0. Exit")

        choice = input("Choose an option: ")

        if choice == '0':
            print("Goodbye!")
            break

        text = input("Enter a string: ")

        if choice == '1':
            idx = int(input("Index to delete: "))
            if 0 <= idx < len(text):
                print("Result:", text[:idx] + text[idx+1:])
            else:
                print("Invalid index.")

        elif choice == '2':
            ch = input("Character to remove: ")
            print("Result:", text.replace(ch, ""))

        elif choice == '3':
            ch = input("Character to insert: ")
            idx = int(input("Index to insert at: "))
            if 0 <= idx <= len(text):
                print("Result:", text[:idx] + ch + text[idx:])
            else:
                print("Invalid index.")

        elif choice == '4':
            print("Result:", text.replace('.', '!'))

        elif choice == '5':
            ch = input("Character to count: ")
            print(f"'{ch}' appears {text.count(ch)} times.")

        elif choice == '6':
            letters = sum(c.isalpha() for c in text)
            digits = sum(c.isdigit() for c in text)
            others = len(text) - letters - digits
            print(f"Letters: {letters}, Digits: {digits}, Others: {others}")

        else:
            print("Invalid option.")

if __name__ == "__main__":
    main()