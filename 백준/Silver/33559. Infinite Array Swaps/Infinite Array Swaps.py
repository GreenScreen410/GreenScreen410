from collections import Counter

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

result = []
for i, count in (Counter(A) & Counter(B)).items():
    result.extend([i] * count)
result.sort()

for i in result:
    A.remove(i)
    B.remove(i)

print(len(result))
print(*(result + A))
print(*(result + B))