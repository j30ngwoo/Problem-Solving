def solve():
	n = int(input())
	formula = list(input())
	for i in range(n):
		if i % 2 == 0:
			formula[i] = int(formula[i])

	is_bracket = [False] * n
	result = -float('inf')

	def oper():
		temp_formula = []
		i = 0
		while i < n:
			if is_bracket[i]:
				a, o, b = temp_formula[-1], formula[i], formula[i + 1] 
				if o == '+':
					temp_formula[-1] = a + b
				elif o == '-':
					temp_formula[-1] = a - b
				else: # '*'
					temp_formula[-1] = a * b
				i += 2
			else:
				temp_formula.append(formula[i])
				i += 1
		
		result = temp_formula[0]
		for i in range(1, len(temp_formula), 2):
			if temp_formula[i] == '+':
				result += temp_formula[i + 1]
			elif temp_formula[i] == '-':
				result -= temp_formula[i + 1]
			else:
				result *= temp_formula[i + 1]

		return result


	def recursion(index):
		nonlocal result
		if index >= n:
			result = max(result, oper())
			return

		recursion(index + 2)
		
		is_bracket[index] = True
		recursion(index + 4)
		is_bracket[index] = False

	recursion(1)
	print(result)

solve()
