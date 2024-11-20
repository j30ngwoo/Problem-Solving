import sys
input = lambda: sys.stdin.readline().strip()

def main():

    def get_max_area(left, right):
        if left == right:
            return heights[left]
        
        mid = (left + right) // 2
        max_area_contains_mid = 0
        min_height = heights[mid]
        sub_left = mid
        sub_right = mid

        for width in range(1, right - left + 2):
            min_height = min(heights[sub_left], heights[sub_right], min_height)
            max_area_contains_mid = max(min_height * width, max_area_contains_mid)

            if sub_right == n - 1:
                sub_left -= 1
            elif sub_left == 0:
                sub_right += 1
            elif heights[sub_left - 1] >= heights[sub_right + 1]:
                sub_left -= 1
            else:
                sub_right += 1

        return max(get_max_area(left, mid), max_area_contains_mid, get_max_area(mid + 1, right))


    while True:
        n, *heights = map(int, input().split())
        if n == 0:
            break
        
        print(get_max_area(0, n - 1))

if __name__ == "__main__":
    main()
