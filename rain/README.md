Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

- Prototype: `def rain(walls)`
- `walls` is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls\[-1\]) are **not** walls, meaning they will not retain water.
- If the list is empty return `0`.

  jesse@ubuntu:~/$ cat 0_main.py
  #!/usr/bin/python3
  """
  0_main
  """
  rain = **import**('0-rain').rain

  if **name** == "**main**":
  walls = [0, 1, 0, 2, 0, 3, 0, 4]
  print(rain(walls))
  walls = [2, 0, 0, 4, 0, 0, 1, 0]
  print(rain(walls))

  jesse@ubuntu:~/$
  jesse@ubuntu:~/$ ./0_main.py
  6
  6
  jesse@ubuntu:~/$

Visual representation of the walls `[0, 1, 0, 2, 0, 3, 0, 4]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/85ef782020ac6efdc7004b62ea86724a552285b4.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231213%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231213T133219Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=07d7ff98308ed7810078f2f255074b032bfb1123d682135301452f676fb9d70b)

Visual representation of the walls `[2, 0, 0, 4, 0, 0, 1, 0]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/9a27c3e4e214e55b3c0b8b1439fdc99b4a184ff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231213%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231213T133219Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=dc8fd93eaca549f62be47e0adc2e7f42b35f75c5bbfd9e995a1c084eee03b59d)
