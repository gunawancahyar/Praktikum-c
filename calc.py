import math

history = []

def calculate(expr):
    try:
        # HANDLE SQRT
        if expr.startswith("sqrt"):
            _, num = expr.split()
            num = float(num)

            if num < 0:
                print("Error: tidak bisa akar negatif")
                return

            r = math.sqrt(num)
            hasil = f"sqrt({num}) = {r}"
            print(hasil)
            history.append(hasil)
            return

        # HANDLE OPERASI BIASA
        a, op, b = expr.split()
        a = float(a)
        b = float(b)

        if op == '+':
            r = a + b
        elif op == '-':
            r = a - b
        elif op == '*':
            r = a * b
        elif op == '/':
            if b == 0:
                print("Error: pembagian nol")
                return
            r = a / b
        elif op == '**':
            r = a ** b
        else:
            print("Operator tidak dikenal")
            return

        hasil = f"{a} {op} {b} = {r}"
        print(hasil)
        history.append(hasil)

    except ValueError:
        print("Format salah! Gunakan: 3 + 4 atau sqrt 9")


# LOOP PROGRAM
while True:
    cmd = input("Input (history / exit / operasi): ")

    if cmd.lower() == "exit":
        break
    elif cmd.lower() == "history":
        if not history:
            print("Belum ada histori")
        else:
            print("\n=== History ===")
            for h in history:
                print(h)
    else:
        calculate(cmd)