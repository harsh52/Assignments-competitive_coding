library(shinydashboard)
library(shiny)
shinyUI(
  dashboardPage(
    dashboardHeader(title = "THis is header",dropdownMenuOutput("msgOutput")
                      # dropdownMenu(type = "message",
                      #               messageItem(from = "Finance update",message="We are broke"),
                      #               messageItem(from = "Sales update", message="I need a job", icon = icon("bar-chart"))
                      #              )
                    ),
    dashboardSidebar(
    sliderInput("bins","Number of Breaks", 1,100,50),
    sidebarMenu(
    menuItem("Dashboard", tabName = "dashboard", icon = icon("dashboard")),
      menuSubItem("Dashboard Finance", tabName = "finance"),
      menuSubItem("Dashboard Sales",tabName = "sales"),
    menuItem("Details Analysis"),
    menuItem("Raw Data")
    )),
   dashboardBody(
     tabItems(
       tabItem(tabName = "dashboard",
               fluidRow(
                 box(plotOutput("histogram")))
     ),
      tabItem(tabName = "finance",h1("F! board")),
      tabItem(tabName = "sales", h2("Sales dashboard"))
     )
   )
)
)