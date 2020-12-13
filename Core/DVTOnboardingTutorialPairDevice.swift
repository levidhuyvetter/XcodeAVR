//
//  PairingViewController.swift
//  Core
//
//  Created by Levi Dhuyvetter on 07/12/2020.
//

import Cocoa

class DVTOnboardingTutorialPairDevice: DVTOnboardingPage, NSTableViewDataSource, NSTableViewDelegate, NSComboBoxDataSource {
	@IBOutlet var tableView:NSTableView!
	@IBOutlet var nameField:NSTextField!
	@IBOutlet var baudField:NSComboBox!
	@IBOutlet var top:NSLayoutConstraint!
	
	let list = AVRDProgrammer.all()
	
	init() {
		super.init(nibName: nil, bundle: Bundle(for: type(of: self)))
	}
	
	required init?(coder: NSCoder) {
		fatalError("init(coder:) has not been implemented")
	}
	
	override func viewWillAppear() {
		self.setValue(self.top, forKey: "topConstraint")
		
		self.nameField.stringValue = self.tutorialController.selectedDeviceForSetup.name
		self.tableViewSelectionDidChange(Notification(name: Notification.Name(rawValue: "")))
		super.viewWillAppear()
	}
	
	func numberOfRows(in tableView: NSTableView) -> Int {
		return self.list.count
	}
	
	func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {
		switch tableColumn?.title {
		case "Name":
			return self.list[row].id
		case "Description":
			return self.list[row].desc
		default:
			return nil
		}
	}
	
	func tableViewSelectionDidChange(_ notification: Notification) {
		if self.list[self.tableView.selectedRow].baud > 0 {
			self.baudField.intValue = Int32(self.list[self.tableView.selectedRow].baud)
		} else {
			self.baudField.stringValue = ""
		}
		self.validate(sender: self)
	}
	
	@IBAction func validate(sender:Any?) {
		self.tutorialController.validateCurrentPage()
	}
	
	override func readyForNextPage() -> Int8 {
		return (self.nameField.stringValue != "" && self.tableView.selectedRow > 0) ? 1 : 0
	}
	
	override func willNavigateToNextPage() -> Int8 {
		let name = self.nameField.stringValue
		let selected = self.tableView.selectedRowIndexes.first! as Int
		let prg = self.list[selected]
		let device = self.tutorialController.selectedDeviceForSetup as! DVTAVRDevice
		
		prg.baud = Int(self.baudField.intValue)
		prg.port = "/dev/\(device.identifier!)"
		
		return device.pair(name: name, programmer: prg) ? 1 : 0
	}
	
	func numberOfItems(in comboBox: NSComboBox) -> Int {
		return 10
	}
	
	func comboBox(_ comboBox: NSComboBox, objectValueForItemAt index: Int) -> Any? {
		return "Test"
	}
}
