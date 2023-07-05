<body>
    <H1>Daily Learning</H1>
<div>
<h2>Basic</h2>
<p>
  Day-1 (Date: 7-4-2023)
  <h3>Why Binary not Decimal</h3>
  <p>
    Computers use binary numbers instead of decimal numbers because binary is well-suited for electronic systems and digital processing. Here are a few reasons why binary is preferred over decimal in computer systems:

  1. Simplicity of representation: Binary numbers consist of only two digits, 0 and 1, which aligns well with the on/off states of electronic switches (transistors). This simplicity makes it easier to design and implement digital circuits.

  2. Hardware compatibility: The internal components of computers, such as logic gates and memory cells, are designed to work with binary signals. Using binary allows for direct compatibility and seamless integration with the underlying electronic hardware.

  3. Reliability and noise resistance: Binary signals are more robust against noise and interference. The distinction between the binary digits 0 and 1 is easier to maintain in electronic circuits, reducing the chances of errors due to signal distortion.

  4. Efficiency in storage: Binary numbers require fewer bits to represent the same value compared to decimal numbers. This efficiency in storage is crucial for memory and storage devices, as it allows for more information to be stored using the same amount of physical resources.

  5. Logical operations: Binary numbers lend themselves well to logical operations like AND, OR, and NOT. These operations form the basis of computational operations in computers. Using binary simplifies the design and implementation of logical circuits and arithmetic units.

  Although decimal numbers are more intuitive for human comprehension, they are not as efficient or compatible with the underlying electronic components and operations performed within computers. Binary numbers, while requiring a mental shift for human users, provide a highly efficient and reliable system for representing and manipulating information in computer systems.
  </p>

  <h4>Number System</h4>
  <pre>
    1.Binary - Two base number.
    2.Octal - Eight base number.
    2.Decimal - Ten base number.
    2.Hexadecimal - Sixteen base number.
  </pre>
  <div>
    <h4>Binary to Decimal</h4>
    <pre>
      <img style="width: 80%;" src="Image/asd.png" alt="">
      </br>
function convertToDecimal(x) {
    let bin = 0;
    let rem, i = 1, step = 1;
    while (x != 0) {
        rem = x % 10;
        x = parseInt(x / 10);
        bin = bin + rem * i;
        i = i * 2;
    }
console.log(`Decimal:  ${bin}`);
}
// take input
//let number = prompt('Enter a Binary number: ');
convertToDecimal(101);
    </pre>
    <h4>Decimal to Binary</h4>
    <pre>
      <img style="width: 80%;" src="Image/binary to decimal.jpg" alt="">

</br>

Other way - decimal 75
75 >= 64 = 1
75 - 64 = 11

11 <= 32 = 0
11 <= 16 = 0

11 >= 8 = 1
11 - 8 = 3

3 >= 2 = 1
3 - 2 = 0

1 >= 1 = 1

64 = 1 
32 = 0 
16 = 0 
8 = 1 
4 = 0 
2 = 1 
1 = 1

75 = 1001011

function convertToBinary(x) {
    let bin = 0;
    let rem, i = 1, step = 1;
    while (x != 0) {
        rem = x % 2;
        console.log(
            `Step ${step++}: ${x}/2, Remainder = ${rem}, Quotient = ${parseInt(x/2)}`
        );
        x = parseInt(x / 2);
        bin = bin + rem * i;
        i = i * 10;
    }
    console.log(`Binary:  ${bin}`);
}
// take input
//let number = prompt('Enter a decimal number: ');
convertToBinary(5);
    </pre>
  </div>

  <h4>Decimal to Octal</h4>
  <pre>
    <img style="width: 80%;" src="Image/decimal-to-octal.png" alt="">
    </br>
function convertToCOtalTOdecimal(x) {
    let bin = 0;
    let rem, i = 1, step = 1;
    while (x != 0) {
        rem = x % 8;
        x = parseInt(x / 8);
        bin = bin + rem * i;
        i = i * 10;    
    }
console.log(`Octal:  ${bin}`);
}
// take input
//let number = prompt('Enter a Decimal number: ');
convertToCOtalTOdecimal(8);

  </pre>
  <h4>Octal to Decimal</h4>
  <pre>
    <img style="width: 80%;" src="Image/octaltodecimal.png" alt="">
    </br>
function convertToDecimalTOOCatal(x) {
    let bin = 0;
    let rem, i = 1, step = 1;
    while (x != 0) {
        rem = x % 10;
        x = parseInt(x / 10);
        bin = bin + rem * i;
        i = i * 8;    
    }
    console.log(`Decimal:  ${bin}`);
}
// take input
//let number = prompt('Enter a Octal number: ');

convertToDecimalTOOCatal(100);
  </pre>
  
  <h4>DIFFERENT BETWEEM INTERPRETER AND COMPILAR</h4>
  A compiler translates the entire source code in a single run. 
  An interpreter translates the entire source code line by line

  <div>
    <h3>#KEYWORDS</h3>
    
    1. High level Language > INTERPRETER(Work line by line) > Machine Language
    2. Assembly language > Assembler > Machine Language
    3. Mid level language ( C )
    4. High level language(python, c++, c# etc)
    5. compiler(GNU, CSS) - A compiler translates the entire source code in a single run
    6. CodeBlocks(IDE-Integrated Development Environment)
    
  </div>
</p>
</div>
</body>
</html>
