class Solution2():
    def count_unique_subsequence(self, s, start, dest, n):
        def count_unique(s, index, curr, dest, n, d):
            if (index, curr) in d:
                return d[(index, curr)]
            
            result = set([])
            if index == len(s):
                return result
            
            result.update(count_unique(s, index + 1, curr, dest, n, d))
            if s[index] == 'l':
                if curr > 0:
                    next_loc = curr - 1
                    if next_loc == dest:
                        result.add('l')
                    for r in count_unique(s, index + 1, next_loc, dest, n, d):
                        result.add('l' + r)
            else:
                if curr + 1 < n:
                    next_loc = curr + 1
                    if next_loc == dest:
                        result.add('r')
                    for r in (count_unique(s, index + 1, next_loc, dest, n, d)):
                        result.add('r' + r)
            
            d[(index, curr)] = result
            return result
        
        return len(count_unique(s, 0, start, dest, n, {}))
        
s = Solution2()
s.count_unique_subsequence('rrlrlr', 1, 2, 6)
