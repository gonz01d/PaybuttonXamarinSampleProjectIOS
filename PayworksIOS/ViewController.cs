﻿using System;

using UIKit;

namespace PayworksIOS
{
    public partial class ViewController : UIViewController
    {
        partial void startTrx(UIButton sender)
        {

           // sender.SetTitle(MPOS.MPMpos.Version, UIControlState.Normal);


            var provider = MPOS.MPMpos.TransactionProviderForMode(MPProviderMode.Mock, "sdlfkjsdlfkj", "asfajk;sflkj");
            var transactionParameters = MPOS.MPTransactionParameters.ChargeWithAmount(new Foundation.NSDecimalNumber("5.00"), MPCurrency.EUR, null);

            var accessoryParameters = MPOS.MPAccessoryParameters.ExternalAccessoryParametersWithFamily(MPAccessoryFamily.MiuraMPI, "com.miura.shuttle", null);

           // var accessoryParameters = MPOS.MPAccessoryParameters.MockAccessoryParameters();
            //sender.SetTitle(transactionParameters.Amount.ToString(), UIControlState.Normal);
            var process = provider.StartTransactionWithParameters(transactionParameters, accessoryParameters, (transactionProcess, transaction) => {
                
            }, (transactionProcess, transaction, transactionProcessDetails) => {
                sender.SetTitle(transactionProcessDetails.Information[0] + " " + transactionProcessDetails.Information[1], UIControlState.Normal);
            }, (transactionProcess, transaction, arg2, arg3) => {
                
            }, (transactionProcess, transaction, transactionProcessDetails) => {
                
            });
        }

        protected ViewController(IntPtr handle) : base(handle)
        {
            // Note: this .ctor should not contain any initialization logic.
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();
            // Perform any additional setup after loading the view, typically from a nib.
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }
    }
}