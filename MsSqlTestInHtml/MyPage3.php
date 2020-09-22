<!DOCTYPE html>
<html>
	<head>
		<title>MsSqlTest - Relations</title>
		<link rel="stylesheet" type="text/css" href="Styles/CommonStyle.css">
		<link rel="stylesheet" type="text/css" href="Styles/MyPage3Style.css">
<?php
		include_once "Pages/db_config.php";
?>
	</head>
	<body>
<?php
        $people = array();
        $relationships = array();
        $relations = array();
?>
		<div class="MyPage3TopSpace">
			<!-- Top spacer. -->
		</div>
		<div class="MyPage3Panel">
			<div class="MyPage3Area">
				<table class="MyPage3Table1">
					<tbody>
						<tr>
							<td class="MyPage3Table1Column1">
							    <div class="MyPage3Results">
    								<table class="MyPage3Table2">
    									<thead class="MyPage3Table2Head">
    										<tr class="TableBorder">
    											<td class="TableBorder">Id</td>
    											<td class="TableBorder">Person1</td>
    											<td class="TableBorder">Relationship</td>
    											<td class="TableBorder">Person2</td>
    										</tr>
    									</thead>
    									<tbody  class="MyPage3Table2Body">
<?php
    										// Get the items from the People table.
                                            $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[People]");
                                                
                                            // Store the items in a Person list.
                                            while ($row = odbc_fetch_row($query))
                                            {
                                                foreach ($row as $cell)
                                                {
                                                    $people[] = $cell;
                                                }
                                            }
                                                
                                            // Get the items from the Relationships table.
                                            $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]");
                                                
                                            // Store the items in a Relationship list.
                                            while ($row = odbc_fetch_row($query))
                                            {
                                                foreach ($row as $cell)
                                                {
                                                    $relationships[] = $cell;
                                                }
                                            }
                                                
    									    // Get the items from the Relations table.
                                            $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE IsDeleted = '0'");
    								            
    								        // Store the items in a Relation list.
                                            while ($row = odbc_fetch_row($query))
                                            {
                                                foreach ($row as $cell)
                                                {
                                                    $relations[] = $cell;
                                                }
                                            }
    											
    								        // Fill the table with the records.
    								        for ($i = 0; $i < count($relations) / 5; $i++)
    								        {
?>
    								            <tr>
    								            	<td class="TableBorder TableContent"><?php echo $relations[$i * 5 + 0]; ?></td>
<?php
                                                    // Substitute the Person1 ids with their names.
                                                    for ($j = 0; $j < count($people) / 6; $j++)
                                                    {
                                                        if ($relations[$i * 5 + 1] == $people[$j * 6 + 0])
                                                        {
?>
    													   <td class="TableBorder TableContent"><?php echo $people[$j * 6 + 1]; ?></td>
<?php
                                                        }
                                                    }
                                                        
                                                    // Substitute the Relationship ids with their names.
                                                    for ($j = 0; $j < count($relationships) / 3; $j++)
                                                    {
                                                        if ($relations[$i * 5 + 2] == $relationships[$j * 3 + 0])
                                                        {
?>
    													   <td class="TableBorder TableContent"><?php echo $relationships[$j * 3 + 1]; ?></td>
<?php
                                                        }
                                                    }
                                                        
                                                    // Substitute the Person2 ids with their names.
                                                    for ($j = 0; $j < count($people) / 6; $j++)
                                                    {
                                                        if ($relations[$i * 5 + 3] == $people[$j * 6 + 0])
                                                        {
?>
    													   <td class="TableBorder TableContent"><?php echo $people[$j * 6 + 1]; ?></td>
<?php
                                                        }
                                                    }
?>
    								            </tr>
<?php
    								        }
?>
    									</tbody>
    								</table>
    							</div>
							</td>
							<td class="MyPage3Table1Column2">
								<table class="MyPage3Table3">
									<tbody>
										<tr class="MyPage3Table3Row1">
											<td>
												<label class="MyPage3ModifyLabel Label">Modify:</label>
												<div class="MyPage3TopModifyContainer">
													<form class="MyPage3Form">
														<div class="MyPage3SelectContainer">
															<label class="MyPage3SelectLabel Label">Select:</label>
															<select class="MyPage3SelectSelect ComboBox" name="MyPage3SelectSelect" id="MyPage3SelectSelect" onchange="select1OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the relations.
                                                                for ($i = 0; $i < count($relations) / 5; $i++)
                                                                {
?>
                                                                   <option><?php echo $relations[$i * 5 + 0]; ?></option>
<?php
                                                                }
?>
															</select>
														</div>
														<div class="MyPage3Person1Container">
															<label class="MyPage3Person1Label Label">Person1:</label>
															<select class="MyPage3Person1ComboBox ComboBox" name="MyPage3Person1ComboBox" id="MyPage3Person1ComboBox" onchange="select2OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the people.
                                                                for ($i = 0; $i < count($people) / 6; $i++)
                                                                {
                                                                    if ($people[$i * 6 + 5] == false)
                                                                    {
?>
                                                                        <option><?php echo $people[$i * 6 + 0]; ?></option>
<?php
                                                                    }
                                                                }
?>
                                                            </select>
														</div>
														<div class="MyPage3RelationshipContainer">
															<label class="MyPage3RelationshipLabel Label">Relationship:</label>
															<select class="MyPage3RelationshipComboBox ComboBox" name="MyPage3RelationshipComboBox" id="MyPage3RelationshipComboBox" onchange="select3OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the relationships.
                                                                for ($i = 0; $i < count($relationships) / 3; $i++)
                                                                {
                                                                    if ($relationships[$i * 3 + 2] == false)
                                                                    {
?>
                                                                        <option><?php echo $relationships[$i * 3 + 0]; ?></option>
<?php
                                                                    }
                                                                }
?>
                                                            </select>
														</div>
														<div class="MyPage3Person2Container">
															<label class="MyPage3Person2Label Label">Person2:</label>
															<select class="MyPage3Person2ComboBox ComboBox" name="MyPage3Person2ComboBox" id="MyPage3Person2ComboBox" onchange="select4OnChange()">
																<option>0</option>
<?php
                                                                // Fill the select options with the ids of the people.
                                                                for ($i = 0; $i < count($people) / 6; $i++)
                                                                {
                                                                    if ($people[$i * 6 + 5] == false)
                                                                    {
?>
                                                                        <option><?php echo $people[$i * 6 + 0]; ?></option>
<?php
                                                                    }
                                                                }
?>
                                                            </select>
														</div>
														<div class="MyPage3Table4Container">
															<table class="MyPage3Table4">
																<tbody>
																	<tr>
																		<td>
																			<input type="submit" value="Add" class="MyPage3AddButton Button" name="MyPage3AddButton" id="MyPage3AddButton" onclick="button2OnClick()" />
																		</td>
																		<td>
																			<input type="submit" value="Edit" class="MyPage3EditButton Button" name="MyPage3EditButton" id="MyPage3EditButton" onclick="button3OnClick()" />
																		</td>
																		<td>
																			<input type="submit" value="Delete" class="MyPage3DeleteButton Button" name="MyPage3DeleteButton" id="MyPage3DeleteButton" onclick="button4OnClick()" />
																		</td>
																	</tr>
																</tbody>
															</table>
														</div>
													</form>
												</div>
											</td>
										</tr>
										<tr class="MyPage3Table3Row2">
											<td>
												<label class="MyPage3HelperLabel">Helper:</label>
												<div class="MyPage3HelperLabelContainer">
													<div class="MyPage3HelperPerson1Container">
														<label class="MyPage3HelperPerson1Label">Person1:</label>
														<input type="text" value="" class="MyPage3HelperPerson1TextBox TextBox" name="MyPage3HelperPerson1TextBox" id="MyPage3HelperPerson1TextBox" readonly />
													</div>
													<div class="MyPage3HelperRelationshipContainer">
														<label class="MyPage3HelperRelationshipLabel">Relationship:</label>
														<input type="text" value="" class="MyPage3HelperRelationshipTextBox TextBox" name="MyPage3HelperRelationshipTextBox" id="MyPage3HelperRelationshipTextBox" readonly />
													</div>
													<div class="MyPage3HelperPerson2Container">
														<label class="MyPage3HelperPerson2Label">Person2:</label>
														<input type="text" value="" class="MyPage3HelperPerson2TextBox TextBox" name="MyPage3HelperPerson2TextBox" id="MyPage3HelperPerson2TextBox" readonly />
													</div>
												</div>
												<div class="MyPage3BottomButtonsContainer">
													<input type="button" value="List" class="MyPage3ListButton Button" name="MyPage3ListButton" id="MyPage3ListButton" onclick="button1OnClick()" />
													<input type="button" value="Close" class="MyPage3CloseButton Button" name="MyPage3CloseButton" id="MyPage3CloseButton" onclick="button5OnClick()" />
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
		<script src="Scripts/MyPage3Script.js"></script>
		<script src="Scripts/jQuery/jquery-1.12.0.min.js"></script>
	</body>
</html>