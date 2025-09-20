Dr. D.Y. Patil Unitech Society’s
Dr. D.Y. Patil Arts, Commerce and Science College Pimpri, Pune-18
Department of Computer Science
Academic Year: 2025-2026
Practical Assignment – 6
Class:- T.Y.B.C.A.(Science)
Subject:- Programming in JAVA Date:-19/09/2025
1. Write a servlet program to display current date and time of server.
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
public class DateTimeServlet extends HttpServlet {
 protected void doGet(HttpServletRequest request, HttpServletResponse
response)
 throws ServletException, IOException {
 response.setContentType("text/html");
 Date currentDate = new Date();
 PrintWriter out = response.getWriter();

 out.println("<html>");
 out.println("<head><title>Current Date and Time</title></head>");
 out.println("<body>");
 out.println("<h1>Current Date and Time</h1>");
 out.println("<p>" + currentDate.toString() + "</p>");
 out.println("</body>");
 out.println("</html>");
 out.close();
 }
}
2. Design a servlet to display “Welcome IP address of client” to first time
visitor. Display “Welcome-back IP address of client” if the user is
revisiting the page. (Use Cookies) (Hint: Use req.getRemoteAddr() to
get IP address of client)
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
public class WelcomeServlet extends HttpServlet {
 private static final long serialVersionUID = 1L;
 protected void doGet(HttpServletRequest request, HttpServletResponse
response)
 throws ServletException, IOException {
 String clientIp = request.getRemoteAddr();
 response.setContentType("text/html");
 PrintWriter out = response.getWriter();
 Cookie[] cookies = request.getCookies();
 boolean isReturningVisitor = false;
 if (cookies != null) {
 for (Cookie cookie : cookies) {
 if (cookie.getName().equals("clientIp") &&
cookie.getValue().equals(clientIp)) {
 isReturningVisitor = true;
 break;
 }
 }
 }
 if (isReturningVisitor) {
 out.println("<html><body>");
 out.println("<h1>Welcome-back, " + clientIp + "</h1>");
 out.println("</body></html>");
 } else {
 Cookie cookie = new Cookie("clientIp", clientIp);
 cookie.setMaxAge(60 * 60 * 24); // Cookie expires in 1 day
 response.addCookie(cookie);
 out.println("<html><body>");
 out.println("<h1>Welcome, " + clientIp + "</h1>");
 out.println("</body></html>");
 }
 out.close();
 }
}
3. Create a JSP page to accept a number from an user and display it in
words: Example: 123 – One Two Three.
<%@ page language="java" %>
<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html>
<head>
 <title>Number to Words Converter</title>
</head>
<body>
 <h2>Number to Words Converter</h2>
 <form action="#" method="post">
 Enter a number: <input type="text" name="number">
 <input type="submit" value="Convert">
 </form>
 <%
 String[] words = {"Zero", "One", "Two", "Three", "Four", "Five",
"Six", "Seven", "Eight", "Nine"};
 String numberStr = request.getParameter("number");
 if (numberStr != null && !numberStr.isEmpty()) {
 try {
 int number = Integer.parseInt(numberStr);
 String[] digits = String.valueOf(number).split("");
 out.println("<p>Number in words: ");
 for (String digit : digits) {
 out.print(words[Integer.parseInt(digit)] + " ");
 }
 out.println("</p>");
 } catch (NumberFormatException e) {
 out.println("<p>Invalid number. Please enter a valid
number.</p>");
 }
 }
 %>
</body>
</html>
4. Write a JSP program to perform Arithmetic operations such as
Addition, Subtraction, Multiplication and Division. Design a HTML to
accept two numbers in text box and radio buttons to display operations.
On submit display result as per the selected operation on next page
using JSP.
<!DOCTYPE html>
<html>
<head>
 <title>Arithmetic Operations</title>
</head>
<body>
 <h2>Arithmetic Operations</h2>
 <form action="Calculate.jsp" method="post">
 Enter first number: <input type="text" name="num1"><br>
 Enter second number: <input type="text" name="num2"><br>
 Select operation:
 <input type="radio" name="operation" value="addition">Addition
 <input type="radio" name="operation"
value="subtraction">Subtraction
 <input type="radio" name="operation"
value="multiplication">Multiplication
 <input type="radio" name="operation" value="division">Division<br>
 <input type="submit" value="Calculate">
 </form>
</body>
</html>
JSP Code:
<%@ page language="java" %>
<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html>
<head>
 <title>Result</title>
</head>
<body>
 <h2>Result</h2>
 <%
 double num1 = Double.parseDouble(request.getParameter("num1"));
 double num2 = Double.parseDouble(request.getParameter("num2"));
 String operation = request.getParameter("operation");
 double result = 0;
 switch (operation) {
 case "addition":
 result = num1 + num2;
 out.println("<p>" + num1 + " + " + num2 + " = " + result +
"</p>");
 break;
 case "subtraction":
 result = num1 - num2;
 out.println("<p>" + num1 + " - " + num2 + " = " + result +
"</p>");
 break;
 case "multiplication":
 result = num1 * num2;
 out.println("<p>" + num1 + " * " + num2 + " = " + result +
"</p>");
 break;
 case "division":
 if (num2 != 0) {
 result = num1 / num2;
 out.println("<p>" + num1 + " / " + num2 + " = " + result +
"</p>");
 } else {
 out.println("<p>Division by zero is not allowed.</p>");
 }
 break;
 default:
 out.println("<p>Invalid operation.</p>");
 }
 %>
</body>
</html>
5. Design the table User (username, password) using Postgre Database.
Design HTML login screen. Accept the user name and password from
the user. Write a servlet program to accept the login name and
password and validates it from the database you have created. If it is
correct then display Welcome.html otherwise display Error.html.
<!DOCTYPE html>
<html>
<head>
 <title>Login</title>
</head>
<body>
 <h2>Login</h2>
 <form action="LoginServlet" method="post">
 Username: <input type="text" name="username"><br>
 Password: <input type="password" name="password"><br>
 <input type="submit" value="Login">
 </form>
</body>
</html>
Servlet Code:
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class LoginServlet extends HttpServlet {
 public void doPost(HttpServletRequest request, HttpServletResponse
response)
 throws ServletException, IOException {
 String username = request.getParameter("username");
 String password = request.getParameter("password");
 boolean isAuthenticated = authenticateUser(username, password);
 if (isAuthenticated) {
 response.sendRedirect("Welcome.html");
 } else {
 response.sendRedirect("Error.html");
 }
 }
 private boolean authenticateUser(String username, String password) {
 try {

Class.forName("org.postgresql.Driver");
Connection
con=DriverManager.getConnection(jdbc:postgresql://localhost:5432/pooja”,admin,
123);
 PreparedStatement ps = conn.prepareStatement(
 "SELECT * FROM User WHERE username = ? AND password =
?"
 );
 ps.setString(1, username);
 ps.setString(2, password);
 ResultSet rs = ps.executeQuery();
 if (rs.next()) {
 conn.close();
 return true;
 } else {
 conn.close();
 return false; }
 } catch (Exception e) {
 e.printStackTrace();
 return false; // Error occurred
 }
 }
}
6. Write a JSP program to display number of times user has visited the
page. (Use cookies)
<%@ page import="java.io.*, javax.servlet.*" %>
<%@ page import="javax.servlet.http.*, java.util.*" %>
<%
 int visitCount = 0;
 Cookie[] cookies = request.getCookies();
 if (cookies != null) {
 for (Cookie cookie : cookies) {
 if (cookie.getName().equals("visitCount")) {
 visitCount = Integer.parseInt(cookie.getValue());
 break;
 }
 }
 }
 visitCount++;
 Cookie visitCookie = new Cookie("visitCount",
String.valueOf(visitCount));
 response.addCookie(visitCookie);
%>
<!DOCTYPE html>
<html>
<head>
 <title>Visit Counter</title>
</head>
<body>
 <h2>Welcome to the Page</h2>
 <p>You have visited this page <%= visitCount %> times.</p>
</body>
</html>
7. Create a JSP page, which accepts user name in a text box and greets the
user according to the time on server side.
<%@ page import="java.util.Calendar" %>
<%@ page import="java.util.GregorianCalendar" %>
<%@ page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
 <title>Greeting Page</title>
 <style>
 .morning { color: red; }
 .afternoon { color: green; }
 .evening { color: blue; }
 </style>
</head>
<body>
 <%
 String username = request.getParameter("username");
 // Get the current time
 Calendar calendar = new GregorianCalendar();
 int hour = calendar.get(Calendar.HOUR_OF_DAY);
 String greeting = "";
 String colorClass = "";
 // Determine the greeting message and color based on the time of day
 if (hour >= 6 && hour < 12) {
 greeting = "Good morning, " + username;
 colorClass = "morning";
 } else if (hour >= 12 && hour < 18) {
 greeting = "Good afternoon, " + username;
 colorClass = "afternoon";
 } else {
 greeting = "Good evening, " + username;
 colorClass = "evening";
 }
 // Format the current date and time
 SimpleDateFormat dateFormat = new
SimpleDateFormat("dd/MM/yyyy");
 SimpleDateFormat timeFormat = new
SimpleDateFormat("HH:mm:ss");
 String date = dateFormat.format(calendar.getTime());
 String time = timeFormat.format(calendar.getTime());
 %>
 <h2 class="<%= colorClass %>"><%= greeting %></h2>
 <p>Today's date: <%= date %></p>
 <p>Current time: <%= time %></p>
</body>
</html>
