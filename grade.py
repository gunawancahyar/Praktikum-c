import csv

grades = []
total = 0
count = 0

with open("data.csv") as f:
    reader = csv.DictReader(f)

    for row in reader:
        akhir = 0.3*float(row['tugas']) + 0.3*float(row['uts']) + 0.4*float(row['uas'])
        
        total += akhir
        count += 1

        if akhir >= 85:
            g = 'A'
        elif akhir >= 70:
            g = 'B'
        elif akhir >= 55:
            g = 'C'
        elif akhir >= 40:
            g = 'D'
        else:
            g = 'E'

        grades.append(g)

print("Rata-rata:", total / count)
print("Jumlah A:", grades.count('A'))
print("Jumlah B:", grades.count('B'))
print("Jumlah C:", grades.count('C'))
print("Jumlah D:", grades.count('D'))
print("Jumlah E:", grades.count('E'))