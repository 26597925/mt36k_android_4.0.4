package android.tclwidget;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.ListView;

public class TCLListView extends ListView{
    public TCLListView(Context context) {
        this(context, null);
    }

    public TCLListView(Context context, AttributeSet attrs) {
        this(context, attrs, com.android.internal.R.attr.tcllistViewStyle);
    }

    public TCLListView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }
}