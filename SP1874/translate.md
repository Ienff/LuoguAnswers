# BWHEELER - Burrows Wheeler Precompression

## 题目描述

**Burrows-Wheeler 变换**（**BWT**，也称为**块排序压缩**）是一种在数据压缩技术(如 bzip2)中使用的算法。该算法由 Michael Burrows 和 David Wheeler 发明。

当一个字符串通过 BWT 转换时，字符本身的值不会发生变化。该转换会重新排列字符的顺序。如果原始字符串中存在多个频繁出现的子串，那么转换后的字符串会在多个位置出现连续重复的字符。这样的特性对压缩非常有利，因为具有连续重复字符的字符串可以通过诸如“前移变换”（move-to-front transform）和“游程编码”（run-length encoding）等技术更容易地进行压缩。

例如，字符串：

 ```
SIX.MIXED.PIXIES.SIFT.SIXTY.PIXIE.DUST.BOXES
```
可以转换为这样的字符串，由于其中包含许多重复字符，因此更容易进行压缩：

 ```
 TEXYDST.E.IXIXIXXSSMPPS.B..E.S.EUSFXDIIOIIIT
```
Burrows-Wheeler 算法的工作流程如下：

- 给定一个输入字符串 **S**，例如："abcba"。
- 列出 **S** 的所有循环移位。
  ```
  eg: "abcba", "bcbaa", "cbaab", "baabc", "aabcb"
  ```
- 接下来，对生成的字符串进行排序。 
  ```
  eg: "aabcb", "abcba", "baabc", "bcbaa", "cbaab"
  ```
- 将这些字符串排列成一个大小为 len(S) x len(S) 的矩阵。
  ```
  aabcb
  abcba
  baabc
  bcbaa
  cbaab
  ```
- 输出包含原始输入字符串的行号（1-based indexing）。同时输出最后一列字符形成的字符串。
  ```
  eg: 2 bacab
  ```
  
 现在，给定 Burrows-Wheeler 变换的输出，你能以此恢复原始的字符串吗？  

**输入格式：**  
输入文件包含多个测试用例。  
每个测试用例的第一行包含一个整数 **R**，表示排序后的矩阵中包含原始输入字符串的行号。  
每个测试用例的第二行包含一个字符串 **Col**，表示网格的最后一列。（1 <= len(Col) <= 1000）  
**Col** 只包含小写字母。 1 <= **R** <= len(Col)。  
输入以一行 R=0 结束，该行不需要处理。

**输出格式：**  
打印 Burrows-Wheeler 算法的原始输入字符串。

**测试数据：**  
30 个测试用例  

**输入样例：**
```
2
bacab
3
rwlb
11
baaabaaaabbbaba
0
```
 **输出样例：**  
```
abcba
rbwl
baaabbbbaaaaaab
```