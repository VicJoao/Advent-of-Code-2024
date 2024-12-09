input = (open('input.txt', 'r').read()).split()
list1 = []
ocorrences = {}
for index, number_str in enumerate(input):
    if index % 2 == 0:
        list1.append(int(number_str))
    else:
        if number_str in ocorrences:  
            ocorrences[number_str] += 1
        else:
            ocorrences[number_str] = 1 

for index, num in enumerate(list1):
    if str(num) in ocorrences:
        list1[index] = num * ocorrences[str(num)]
    else:
        list1[index] = 0
sum = 0
for num in list1:
    sum += num
print(sum)