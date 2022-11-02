package main

import "fmt"

type Tuple struct {
	First  int
	Second int
}

func exist(board [][]byte, word string) bool {
	maxCols := len(board[0])
	maxRows := len(board)
	var set = map[Tuple]struct{}{}

	var contains = func(r, c int) bool {
		if _, ok := set[Tuple{r, c}]; ok {
			return true
		}
		return false
	}

	var dfs func(row, col int, i int) bool
	dfs = func(row, col int, i int) bool {
		if i == len(word) {
			return true
		}

		if row >= maxRows || col >= maxCols ||
			row < 0 || col < 0 ||
			word[i] != board[row][col] ||
			contains(row, col) {
			return false
		}

		set[Tuple{row, col}] = struct{}{}

		res := dfs(row+1, col, i+1) || dfs(row, col+1, i+1) ||
			dfs(row-1, col, i+1) || dfs(row, col-1, i+1)

		delete(set, Tuple{row, col})

		return res
	}

	for i := 0; i < maxRows; i++ {
		for j := 0; j < maxCols; j++ {
			if dfs(i, j, 0) {
				return true
			}
		}
	}
	return false
}

func main() {
	var board = [][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}

	fmt.Println(exist(board, "SEE"))
}
