unsigned long CalcDayNumFromDate(unsigned int y, unsigned int m, unsigned int d)
{
  m = (m + 9) % 12;
  y -= m / 10;
  unsigned long dn = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);

  return dn;
}


string CalcDayOfWeek(int y, unsigned long m, unsigned long d)
{
  string day[] = {
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday"
  };

  unsigned long dn = CalcDayNumFromDate(y, m, d);

  return day[dn % 7];
}