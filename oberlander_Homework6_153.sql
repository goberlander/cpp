-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Mar 10, 2018 at 11:13 PM
-- Server version: 5.6.38
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `webd153`
--

-- --------------------------------------------------------

--
-- Table structure for table `freelance`
--

CREATE TABLE `freelance` (
  `freelance_id` int(11) NOT NULL,
  `client_info_id` int(11) NOT NULL,
  `client_services_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `freelance`
--
ALTER TABLE `freelance`
  ADD PRIMARY KEY (`freelance_id`),
  ADD KEY `client_info_id` (`client_info_id`),
  ADD KEY `client_services_id` (`client_services_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `freelance`
--
ALTER TABLE `freelance`
  MODIFY `freelance_id` int(11) NOT NULL AUTO_INCREMENT;


-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Mar 10, 2018 at 11:14 PM
-- Server version: 5.6.38
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `webd153`
--

-- --------------------------------------------------------

--
-- Table structure for table `client_info`
--

CREATE TABLE `client_info` (
  `client_info_id` int(10) UNSIGNED NOT NULL,
  `freelance_id` int(11) NOT NULL,
  `first_name` varchar(25) NOT NULL,
  `last_name` varchar(25) NOT NULL,
  `email` varchar(255) NOT NULL,
  `url` varchar(255) NOT NULL,
  `city` varchar(255) NOT NULL,
  `state` char(15) NOT NULL,
  `country` varchar(100) NOT NULL,
  `phone` int(15) NOT NULL,
  `contact` enum('0','1') NOT NULL,
  `comments` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `client_info`
--
ALTER TABLE `client_info`
  ADD PRIMARY KEY (`client_info_id`),
  ADD KEY `freelance_id` (`freelance_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `client_info`
--
ALTER TABLE `client_info`
  MODIFY `client_info_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;




-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Mar 10, 2018 at 11:15 PM
-- Server version: 5.6.38
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `webd153`
--

-- --------------------------------------------------------

--
-- Table structure for table `client_services`
--

CREATE TABLE `client_services` (
  `client_services_id` int(10) UNSIGNED NOT NULL,
  `freelance_id` int(11) NOT NULL,
  `website` varchar(255) NOT NULL,
  `databaseCode` varchar(255) NOT NULL,
  `corporateDesign` varchar(255) NOT NULL,
  `programming` varchar(255) NOT NULL,
  `multimedia` varchar(255) NOT NULL,
  `other` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `client_services`
--
ALTER TABLE `client_services`
  ADD PRIMARY KEY (`client_services_id`),
  ADD KEY `freelance_id` (`freelance_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `client_services`
--
ALTER TABLE `client_services`
  ADD CONSTRAINT `client_services_ibfk_1` FOREIGN KEY (`freelance_id`) REFERENCES `freelance` (`freelance_id`);
