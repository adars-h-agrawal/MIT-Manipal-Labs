# Lab 8 – VC# Front-End for Oracle Database (Insurance)

This C# console application connects a Visual Studio frontend to an Oracle backend using ODP.NET, executing queries from Lab 3 and Lab 4.

## Project Overview

- **Program.cs** – Main entry that calls query execution methods.
- **DatabaseHelper.cs** – Encapsulates Oracle database connectivity and query methods.
- **app.config** – Holds the ODP.NET connection string for your Oracle DB.

## Prerequisites

- Visual Studio 2012 or later
- Oracle database access with host `172.16.54.24`, port `1521`, service `ictorcl`
- Reference to `Oracle.ManagedDataAccess` in your project

## Usage

1. Clone or download this repo.
2. Open `InsuranceLab8.sln` in Visual Studio.
3. Ensure References include `Oracle.ManagedDataAccess`.
4. Build and run the project.
5. The console will output results for your lab queries.

## Example Queries Included

- Lab 3 Query 3: Owner-wise count and damage sum
- Lab 4 Q1: Unique car owners in accidents for 2008

_You can add more query methods in `DatabaseHelper.cs` following the existing pattern._