class Solution:
	# @param	A	   a list of integers
	# @param	elem	an integer, value need to be removed
	# @return an integer
	def removeElement(self, A, elem):
		length = len(A)
		ret = -1
		for i in range(length):
			if A[i] != elem:
				ret += 1
				if ret < i:
					A[ret] = A[i]

		return ret+1;
