def lengthOfLongestSubstring(s: str) -> int:
    if not s:
        return 0
    bowl = set()
    max_len = 0
    sub_len = 0
    length_s = len(s)
    for id in range(length_s):
        bowl.clear()
        sub_len = 0
        if max_len + id > length_s:
            break
        for start in range(id, length_s):
            if s[start] in bowl:
                break
            else:
                sub_len += 1
                bowl.add(s[start])
        if max_len < sub_len:
            max_len = sub_len
    return max_len


maxOfLen = lengthOfLongestSubstring("abcdafghn")
print(maxOfLen)
