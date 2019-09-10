n, m = list(map(int, input().split()))
# n, m =3, 3
class solution:
    def __init__(self,n, m):
        self.count = 0
        self.n = n
        self.m = m
    def solu(self):
        path = []
        posi = 0
        self.backtrack(path, posi)
        return self.count
    def backtrack(self, path, posi):
        if len(path) == self.m:
            self.count += 1
            return

        for j in range(posi, self.n):
            if path and j < path[-1]:
                continue
            path.append(j)
            self.backtrack(path, posi)
            path.pop()
so = solution(n, m)
