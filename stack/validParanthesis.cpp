bool isValidParenthesis(string s)
{
  stack<char> str;
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    // opening brack then push
    // close brack , check top and pop
    if (ch == '(' || ch == '[' || ch == '{')
    {
      str.push(ch);
    }
    else
    {
      if (!str.empty())
      {
        char top = str.top();

        // close brack
        if ((ch == ')' && top == '(') || (ch == ']' && top == '[') ||
            (ch == '}' && top == '{'))
        {
          str.pop();
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
  }
  if (str.empty())
  {
    return true;
  }
  else
  {
    return false;
  }
}