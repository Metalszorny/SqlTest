<!DOCTYPE html>
<html>
	<head>
		<title>MySqlTest - Relationships</title>
		<link rel="stylesheet" type="text/css" href="Styles/CommonStyle.css">
		<link rel="stylesheet" type="text/css" href="Styles/MyPage2Style.css">
<?php
		include_once "Pages/db_config.php";
?>
	</head>
	<body>
<?php
        $relationships = array();
?>
		<div class="MyPage2TopSpace">
			<!-- Top spacer. -->
		</div>
		<div class="MyPage2Panel">
			<div class="MyPage2Area">
				<table class="MyPage2Table1">
					<tbody>
						<tr>
							<td class="MyPage2Table1Column1">
							    <div class="MyPage2Results">
    								<table class="MyPage2Table2">
    									<thead class="MyPage2Table2Head">
    										<tr class="TableBorder">
    											<td class="TableBorder">Id</td>
    											<td class="TableBorder">Type</td>
    										</tr>
    									</thead>
    									<tbody class="MyPage2Table2Body">
<?php
    										// Get the items from the Relationships table.
    										$query = mysql_query("SELECT * FROM MySqlTestDatabase.Relationships WHERE IsDeleted = '0'");
    								            
    								        // Store the items in a Relationship list.
                                            while ($row = mysql_fetch_assoc($query))
                                            {
                                                foreach ($row as $cell)
                                                {
                                                    $relationships[] = $cell;
                                                }
                                            }
    											
    								        // Fill the table with the records.
    								        for ($i = 0; $i < count($relationships) / 3; $i++)
    								        {
?>
    								            <tr>
    								            	<td class="TableBorder TableContent"><?php echo $relationships[$i * 3 + 0]; ?></td>
                                                    <td class="TableBorder TableContent"><?php echo $relationships[$i * 3 + 1]; ?></td>
    								            </tr>
<?php
    								        }
?>
    									</tbody>
    								</table>
    							</div>
							</td>
							<td class="MyPage2Table1Column2">
								<table class="MyPage2Table3">
									<tbody>
										<tr class="MyPage2Table3Row1">
											<td>
												<label class="MyPage2ModifyLabel Label">Modify:</label>
												<div class="MyPage2TopModifyContainer">
													<form class="MyPage2Form">
														<div class="MyPage2SelectContainer">
															<label class="MyPage2SelectLabel Label">Select:</label>
															<select class="MyPage2SelectSelect ComboBox" name="MyPage2SelectSelect" id="MyPage2SelectSelect" onchange="select1OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the relationships.
                                                                for ($i = 0; $i < count($relationships) / 3; $i++)
                                                                {
?>
                                                                   <option><?php echo $relationships[$i * 3 + 0]; ?></option>
<?php
                                                                }
?>
															</select>
														</div>
														<div class="MyPage2TypeContainer">
															<label class="MyPage2TypeLabel Label">Type:</label>
															<input type="text" value="" class="MyPage2TypeTextBox TextBox" name="MyPage2TypeTextBox" id="MyPage2TypeTextBox" />
														</div>
														<div class="MyPage2Table4Container">
															<table class="MyPage2Table4">
																<tbody>
																	<tr>
																		<td>
																			<input type="submit" value="Add" class="MyPage2AddButton Button" name="MyPage2AddButton" id="MyPage2AddButton" onclick="button2OnClick()" />
																		</td>
																		<td>
																			<input type="submit" value="Edit" class="MyPage2EditButton Button" name="MyPage2EditButton" id="MyPage2EditButton" onclick="button3OnClick()" />
																		</td>
																		<td>
																			<input type="submit" value="Delete" class="MyPage2DeleteButton Button" name="MyPage2DeleteButton" id="MyPage2DeleteButton" onclick="button4OnClick()" />
																		</td>
																	</tr>
																</tbody>
															</table>
														</div>
													</form>
												</div>
											</td>
										</tr>
										<tr class="MyPage2Table3Row2">
											<td>
												<div class="MyPage2BottomButtonsContainer">
													<input type="button" value="List" class="MyPage2ListButton Button" name="MyPage2ListButton" id="MyPage2ListButton" onclick="button1OnClick()" />
													<input type="button" value="Close" class="MyPage2CloseButton Button" name="MyPage2CloseButton" id="MyPage2CloseButton" onclick="button5OnClick()" />
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
		<script src="Scripts/MyPage2Script.js"></script>
		<script src="Scripts/jQuery/jquery-1.12.0.min.js"></script>
	</body>
</html>