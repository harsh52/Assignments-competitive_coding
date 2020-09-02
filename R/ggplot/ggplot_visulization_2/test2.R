
library(ggplot2)
library(tidyverse)
library(plotly)

"bydir.csv" %>% 
  read_csv() -> bydir

cols_of_interest <- c("direction","alpha","source")

#bydir$direction <- factor(bydir$direction, levels = bydir$direction)

bydir %>% 
  select(all_of(cols_of_interest))->p1
p1 %>% 
  ggplot()+
  geom_line(aes(x = direction,
                y = alpha,
                color = source,
                group=source,
                linetype = source
                #group=rev(source)
                #shape = factor(source)
                ),
            size=2) +
  scale_x_discrete(limits=p1$direction) +
  aes(group=rev(alpha)) +
  geom_point(aes(x=direction,
                 y=alpha,
                 color=source,
                 group=source),
             size=3
             ) +
  labs(title = "M2 Nundle : alpha comparison",
       x="Direction",
       y="Shear Param : alpha",
       color = "")+
  theme_minimal() +
  theme(
        legend.text = element_text(size = 9),
        legend.title = element_blank(),
        panel.grid.minor = element_blank(),
        axis.title = element_text(color = "black", size = 12),
        axis.text.x = element_text(face = "bold", size = 8), 
        axis.text.y = element_text(face = "bold", size = 8), 
        plot.title = element_text(size = 18)
        )





