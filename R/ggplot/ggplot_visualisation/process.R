#intro to ggplot
library(ggplot2)
qplot(data=msleep, #data
      x=conservation, #arrange data in certain order
      geom='bar')     #arrange data in certain geom

#now using official ggplot
ggplot(data=economics,
       mapping = aes(x=date, y=unemploy)) + geom_point() 

#next tutorial