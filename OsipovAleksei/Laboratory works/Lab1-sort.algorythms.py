#Variant 6
#Algo1 Сортировка выбором
arr = [1, 5, 7, 9, 0, 5, 3, 5, 5, 8, 9, 6, 8, 4, 3, 6, 2, 4, 6, 7, 8, 0]

i = 0
while i < len(arr)-1:
    m = i
    j = i + 1
    while j < len(arr):
        if arr[j] < arr[m]:
            m = j
        j += 1
    arr[i], arr[m] = arr[m], arr[i]
    i += 1

print(arr)

#Algo2 Сортировка слиянием
array2 = [14, 5, 7, 9, 70, 5, 3, 5, 5, 8, 9, 46, 8, 4, 32, 6, 2, 44, 6, 78, 8, 100]

def Sort(array2, left_index, right_index):
    if left_index >= right_index:
        return
    mid = (left_index + right_index) // 2
    Sort(array2, left_index, mid)
    Sort(array2, mid + 1, right_index)
    Merge(array2, left_index, right_index, mid)

def Merge(array2, left, right, mid):
        left_copy = array2[left:mid + 1]
        right_copy = array2[mid + 1:right + 1]

        left_copy_index = 0
        right_copy_index = 0
        sorted_index = left

        while left_copy_index < len(left_copy) and right_copy_index < len(right_copy):

            if left_copy[left_copy_index] <= right_copy[right_copy_index]:
                array2[sorted_index] = left_copy[left_copy_index]
                left_copy_index = left_copy_index + 1
            else:
                array2[sorted_index] = right_copy[right_copy_index]
                right_copy_index = right_copy_index + 1

            sorted_index = sorted_index + 1

        while left_copy_index < len(left_copy):
            array2[sorted_index] = left_copy[left_copy_index]
            left_copy_index = left_copy_index + 1
            sorted_index = sorted_index + 1

        while right_copy_index < len(right_copy):
            array2[sorted_index] = right_copy[right_copy_index]
            right_copy_index = right_copy_index + 1
            sorted_index = sorted_index + 1

Sort(array2, 0, len(array2)-1)
print(array2)
