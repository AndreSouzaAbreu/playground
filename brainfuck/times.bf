>,            // gets A
>>,           // gets B
[-<<          // goes to A
  [-<+>>+<]   // adds A to TMP (right) and to C (left)
  <[->+<]     // restore A by moving TMP to where A was
  >>>         // move to where B is
]             // finish loop
<.            // move data pointer to C, then prints it
