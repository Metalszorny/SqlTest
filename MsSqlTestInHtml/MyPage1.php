<!DOCTYPE html>
<html>
	<head>
		<title>MsSqlTest - People</title>
		<link rel="stylesheet" type="text/css" href="Styles/CommonStyle.css">
		<link rel="stylesheet" type="text/css" href="Styles/MyPage1Style.css">
<?php
		include_once "Pages/db_config.php";
?>
	</head>
	<body>
<?php
		$people = array();
?>
		<div class="MyPage1TopSpace">
			<!-- Top spacer. -->
		</div>
		<div class="MyPage1Panel">
			<div class="MyPage1Area">
				<table class="MyPage1Table1">
					<tbody>
						<tr>
							<td class="MyPage1Table1Column1">
							    <div class="MyPage1Results">
							        <table class="MyPage1Table2">
                                        <thead class="MyPage1Table2Head">
                                            <tr class="TableBorder">
                                                <td class="TableBorder">Id</td>
                                                <td class="TableBorder">Name</td>
                                                <td class="TableBorder">Mothername</td>
                                                <td class="TableBorder">Location</td>
                                                <td class="TableBorder">Birthdate</td>
                                            </tr>
                                        </thead>
                                        <tbody class="MyPage1Table2Body">
<?php
                                            // Get the items from the People table.
                                            $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE IsDeleted = 0");
                                            
                                            // Store the items in a Person list.
                                            while ($row = odbc_fetch_row($query))
                                            {
                                                foreach ($row as $cell)
                                                {
                                                    $people[] = $cell;
                                                }
                                            }
    
                                            // Fill the table with the records.
                                            for ($i = 0; $i < count($people) / 6; $i++)
                                            {
?>
                                                <tr>
                                                    <td class="TableBorder TableContent"><?php echo $people[$i * 6 + 0]; ?></td>
                                                    <td class="TableBorder TableContent"><?php echo $people[$i * 6 + 1]; ?></td>
                                                    <td class="TableBorder TableContent"><?php echo $people[$i * 6 + 2]; ?></td>
                                                    <td class="TableBorder TableContent"><?php echo $people[$i * 6 + 3]; ?></td>
                                                    <td class="TableBorder TableContent"><?php echo explode(" ", $people[$i * 6 + 4])[0]; ?></td>
                                                </tr>
<?php
                                            }
?>
                                        </tbody>
                                    </table>
							    </div>
							</td>
							<td class="MyPage1Table1Column2">
								<table class="MyPage1Table3">
									<tbody>
										<tr class="MyPage1Table3Row1">
											<td>
												<label class="MyPage1ModifyLabel Label">Modify:</label>
												<div class="MyPage1TopModifyContainer">
													<form class="MyPage1Form" method="post">
														<div class="MyPage1SelectContainer">
															<label class="MyPage1SelectLabel Label">Select:</label>
															<select class="MyPage1SelectSelect ComboBox" name="MyPage1SelectSelect" id="MyPage1SelectSelect" onchange="select1OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the people.
																for ($i = 0; $i < count($people) / 6; $i++)
																{
?>
																    <option><?php echo $people[$i * 6 + 0]; ?></option>
<?php
																}
?>
															</select>
														</div>
														<div class="MyPage1NameContainer">
															<label class="MyPage1NameLabel Label">Name:</label>
															<input type="text" value="" class="MyPage1NameTextBox TextBox" name="MyPage1NameTextBox" id="MyPage1NameTextBox" />
														</div>
														<div class="MyPage1MothernameContainer">
															<label class="MyPage1MothernameLabel Label">Motherame:</label>
															<input type="text" value="" class="MyPage1MothernameTextBox TextBox" name="MyPage1MothernameTextBox" id="MyPage1MothernameTextBox" />
														</div>
														<div class="MyPage1LocationContainer">
															<label class="MyPage1LocationLabel Label">Location:</label>
															<input type="text" value="" class="MyPage1LocationTextBox TextBox" name="MyPage1LocationTextBox" id="MyPage1LocationTextBox" />
														</div>
														<div class="MyPage1BirthdateContainer">
															<label class="MyPage1BirthdateLabel Label">Birthdate:</label>
															<input type="text" value="" class="MyPage1BirthdateTextBox TextBox" name="MyPage1BirthdateTextBox" id="MyPage1BirthdateTextBox" />
														</div>
														<div class="MyPage1Table4Container">
															<table class="MyPage1Table4">
																<tbody>
																	<tr>
																		<td>
																			<input type="button" value="Add" class="MyPage1AddButton Button" name="MyPage1AddButton" id="MyPage1AddButton" onclick="button2OnClick()" />
																		</td>
																		<td>
																			<input type="button" value="Edit" class="MyPage1EditButton Button" name="MyPage1EditButton" id="MyPage1EditButton" onclick="button3OnClick()" />
																		</td>
																		<td>
																			<input type="button" value="Delete" class="MyPage1DeleteButton Button" name="MyPage1DeleteButton" id="MyPage1DeleteButton" onclick="button4OnClick()" />
																		</td>
																	</tr>
																</tbody>
															</table>
														</div>
													</form>
												</div>
											</td>
										</tr>
										<tr class="MyPage1Table3Row2">
											<td>
												<div class="MyPage1BottomButtonsContainer">
													<input type="button" value="List" class="MyPage1ListButton Button" name="MyPage1ListButton" id="MyPage1ListButton" onclick="button1OnClick()" />
													<input type="button" value="Close" class="MyPage1CloseButton Button" name="MyPage1CloseButton" id="MyPage1CloseButton" onclick="button5OnClick()" />
												</div>
											</td>
										</tr>
									</tbody>
								</table>
							</td>
						</tr>
					</tbody>
				</table>
			</div>
		</div>
		<script src="Scripts/MyPage1Script.js"></script>
		<script src="Scripts/jQuery/jquery-1.12.0.min.js"></script>
	</body>
</html>