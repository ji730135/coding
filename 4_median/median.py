# 第一种解法
def findMedianSortedArrays(nums1, nums2) -> float:
    nums = []
    i = j = 0
    while i < len(nums1) and j < len(nums2):
        if nums1[i] < nums2[j]:
            nums.append(nums1[i])
            i += 1
        else:
            nums.append(nums2[j])
            j += 1
    while i < len(nums1):
        nums.append(nums1[i])
        i += 1
    while j < len(nums2):
        nums.append(nums2[j])
        j += 1
    length = len(nums)
    if (length % 2) == 0:
        median = (nums[int(length/2)-1] + nums[int(length/2)]) / 2.0
    else:
        median = nums[int(length/2)] * 1.0
    return median


findMedianSortedArrays([3, 4], [1, 2])
