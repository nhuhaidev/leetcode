/****** Script for SelectTopNRows command from SSMS  ******/
/*phep ket*/
--SELECT *
--  FROM Customers,Orders
-- where Customers.CustomerID=Orders.CustomerID;
/*Cau 3*/
select [CustomerID],[CompanyName],[ContactName],[Address],[Country],[City]	
	from Customers
	where Customers.City='London' OR  Customers.City='France'
/*Cau 4*/
select [CustomerID],[CompanyName],[ContactName],[Address],[Country],[City],[ContactTitle]
	from Customers
	where ContactTitle ='Owner' or ContactTitle = 'Sales Manager'
	order by Country DESC
/*Cau 5*/
select [CustomerID],[CompanyName],[ContactName],[Address],[Country],[City],[ContactTitle]
	from Customers
	where ContactTitle !='Owner' or ContactTitle = 'Sales Manager'
	order by Country DESC
/*Cau 6*/
select OrderID,OrderDate,CompanyName,LastName
	from Customers,Orders,Employees
	where OrderDate > '1996-12-31 00:00:00.000' and OrderDate < '1997-07-01'
/*Cau 7*/
select OrderID,OrderDate,CompanyName,LastName
	from Customers,Orders,Employees
	where DATEPART(YEAR,Orders.OrderDate)in(1997)
		and DATEPART(MONTH,Orders.OrderDate)in(2)
/*Cau 8*/
select OrderID,OrderDate,CompanyName,LastName
	from Customers,Orders,Employees
	where DATEPART(MONTH,Orders.OrderDate)in(4)
/*Cau 9*/
select OrderID,OrderDate,CompanyName,LastName
	from Customers,Orders,Employees
	where DATEPART(DAY,Orders.OrderDate)%2=0
/*Cau 10*/
select OrderID,OrderDate,CompanyName,LastName
	from Customers,Orders,Employees
	where DATEPART(DAY,Orders.OrderDate)in(5,13,14,23)
/*Cau 11*/
select OrderID,OrderDate,ShipperID,Freight
	from Customers,Orders,Shippers
	where ShipperID = '2' and DATEPART(YEAR,Orders.OrderDate)in(1997)
/*Cau 12*/
select ProductID,ProductName,CompanyName,UnitPrice,UnitsInStock
	from Products,Suppliers,Categories
	where SUBSTRING(Products.ProductName,1,2)='Ch'
/*Cau 13*/
select ProductID,CompanyName,UnitPrice,UnitsInStock,Discontinued
	from Products,Suppliers
	where Discontinued='1' and UnitsInStock > 0
--Cau 14
select CompanyName,ContactName,Country,Phone,Fax
	from Suppliers
	where Country != 'USA'
--Cau 15
select CompanyName,ContactName,Country,Phone,Fax
	from Suppliers
	where Country not in('Brazil','Italy','Spain','Venezuela','UK')
--Cau 16
select OrderID,CompanyName,LastName,OrderDate,ShipCountry,ShippedDate,Freight
	from Orders,Customers,Employees
	where ShipCountry = 'USA' and Freight>300
		or ShipCountry = 'Argentina' and Freight<5
--Cau 17
select OrderID,CompanyName,LastName,OrderDate,ShipCountry,Freight
	from Orders,Customers,Employees
	where DATEPART(Day,Orders.OrderDate)in(25)
--Cau 18
SELECT 
    Orders.OrderID,
    Customers.CompanyName,
    Employees.LastName,
    Orders.OrderDate,
    Orders.ShipCountry,
    Orders.Freight,
    Orders.Freight * 1.1 AS NewFreight
FROM 
    Orders,Customers,Employees
where datepart(year,Orders.OrderDate)in(1997)
	and datepart(month,Orders.OrderDate)in(4)
--Cau 19