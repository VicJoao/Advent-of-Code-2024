input = (open('input.txt', 'r').read()).split()
list1 = []
list2 = []
for index, number_str in enumerate(input):
    if index % 2 == 0:
        list1.append(int(number_str))
    else:
        list2.append(int(number_str))
list1.sort()
list2.sort()
sum = sum(abs(a - b) for a, b in zip(list1, list2))
print(sum)

