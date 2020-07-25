library(shinydashboard)
library(shiny)
shinyUI(
  dashboardPage(
    dashboardHeader(title = "THis is header"),
    dashboardSidebar(
    menuItem("Dashboard"),
      menuSubItem("Dashboard Finance"),
      menuSubItem("Dashboard Sales"),
    menuItem("Details Analysis"),
    menuItem("Raw Data")
    ),
   dashboardBody()
)
)