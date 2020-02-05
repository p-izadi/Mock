t = int(input())
inf = 10**10
for _ in range(t):
    n = int(input())
    route = input()
    location = [(0, 0)]
    loc_dict = {(0, 0): [0]}
    l, r = 0, n+1
    for i in range(1, n+1):
        dx, dy, c = 0, 0, route[i-1]

        if c == 'R':
            dx = 1
        elif c == 'L':
            dx = -1
        elif c == 'U':
            dy = 1
        elif c == 'D':
            dy = -1

        location.append((location[i-1][0]+dx, location[i-1][1]+dy))
        try:
            loc_dict[location[i]].append(i)
        except KeyError:
            loc_dict[location[i]] = [i]

    l, r = 0, inf
    for loc in location:
        for t1 in loc_dict[loc]:
            for t2 in loc_dict[loc]:
                if t2 - t1 > 0 and t2 - t1 < r - l:
                    l = t1
                    r = t2
    if l == inf or r == inf:
        print(-1)
    else:
        print(l+1, r)
